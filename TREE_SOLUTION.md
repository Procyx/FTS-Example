# The Tree - Solution
Input « code.txt » is a **sequence of numbers**, given in groups of 3.
<br>Given this amount of data, it seems unlikely that we should treat them directly.
 
We can recognize a group of 3 digits as **a color**, because the pattern seems very similar to *RGB*.
<br>But, the **values are not in a valid range** ([0;1] or [0;255]). 
<br>The highest value we can find is ‘510’, and the smallest is ‘0’.
<br>However, we can see that *each number* of this file is a *multiple of 2*. Also, **510** = **2** * **255**. 
<br>It seems fair to think that these numbers are ***Red*/*Green*/*Blue* values** of a pixel, multiplied by **2**.

So, one group could be the color of one pixel. There are *65536 lines/groups* given in this file -> **65536 pixels**.
<br>We notice that **65536** = **256** * **256**. 256x256 are common dimensions for low-quality images.
<br>Moreover, the second Input (« *tree.png* ») is an image with *256x256 dimensions*, and *the required skills indicate the <br>notions of image and pixels*.
 
Using the java language, we make a program that converts « **code.txt** » file into a *256x256 image*. (*Any language can be used*):

```java    
    // Reader
    final BufferedReader reader = new BufferedReader(new FileReader(new File(System.getProperty("user.home") + "/Desktop/code.txt")));
    // Result image
    final BufferedImage result = new BufferedImage(256, 256, BufferedImage.TYPE_INT_ARGB);
    
    int x = 0, y = 0;
    
    String line;
    while ((line = reader.readLine()) != null)
    {
	    final String[] splitted = line.split(";");
    
		// Values divided by 2 (decoded)
	    final int rVal = Integer.valueOf(splitted[0]) / 2;
	    final int gVal = Integer.valueOf(splitted[1]) / 2;
        final int bVal = Integer.valueOf(splitted[2]) / 2;
    
        // Setting result pixel
        result.setRGB(x, y, new java.awt.Color(rVal, gVal, bVal).getRGB());
    
        // Updated pixel coordinates
        x++;
        if(x >= 256)
        {
             y++;
             x = 0;
        }
    }
    
    // Output
    final File out = new File(System.getProperty("user.home") + "/Desktop/image_from_txt.png");
    ImageIO.write(result, "png", out);
```

The result seems to **confirm our track**, the *result is a picture of tree* that seems identical to the "*tree.png*" image:


<img align="left" width="256" height="256" src="https://image.noelshack.com/fichiers/2018/05/6/1517670874-tree.png">
<img align="right" width="256" height="256" src="https://image.noelshack.com/fichiers/2018/05/6/1517671308-image-from-txt.png">

<br><center>  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<--  <b>tree.png</b> (Input 1)</center>
<br><br><center><b> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;image_from_txt.png</b>  --><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Program Output)</center>
<br><br><br><br><br><br>

But are these images *really identical*?
<br>Using another program, we make sure that the 2 images are **identical**:

```java
    // Tree.png
    final BufferedImage i1 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/tree.png"));
    // Image from txt
    final BufferedImage i2 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/image_from_txt.png"));
    
    for(int y = 0; y < 256; y++)
        for(int x = 0; x < 256; x++)
        {
            final int rgb1 = i1.getRGB(x, y);
            final int rgb2 = i2.getRGB(x, y);
    
            final int red1 = (rgb1 & 0x00ff0000) >> 16, green1 = (rgb1 & 0x0000ff00) >> 8, blue1 = rgb1 & 0x000000ff;
            final int red2 = (rgb2 & 0x00ff0000) >> 16, green2 = (rgb2 & 0x0000ff00) >> 8, blue2 = rgb2 & 0x000000ff;
    
            final boolean same1 = red1 == red2 && green1 == green2 && blue1 == blue2;
    
            // Exist if a pixel is different
            if(!same1)
            {
                System.out.println("Images are not equals!");
                System.exit(0);
            }
        }
    
    System.out.println("Images are equals!");
```

And, **they are not**! 
*Program Output:* `Images are not equals!`

So, now we could try to represent this difference (**visually**).
We create a program to *generate another image (**delta.png**) on which we only write pixels which are not identical* in both images **tree.png** and **image_from_txt.png**.

```java
    // Tree.png
    final BufferedImage i1 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/tree.png"));
    // Image form text
    final BufferedImage i2 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/image_from_txt.png"));
    // Result
    final BufferedImage delta = new BufferedImage(256, 256, BufferedImage.TYPE_INT_ARGB);
    
    for(int y = 0; y < 256; y++)
        for(int x = 0; x < 256; x++)
        {
            final int rgb1 = i1.getRGB(x, y);
            final int rgb2 = i2.getRGB(x, y);
    
            final int red1 = (rgb1 & 0x00ff0000) >> 16, green1 = (rgb1 & 0x0000ff00) >> 8, blue1 = rgb1 & 0x000000ff;
            final int red2 = (rgb2 & 0x00ff0000) >> 16, green2 = (rgb2 & 0x0000ff00) >> 8, blue2 = rgb2 & 0x000000ff;
    
            final boolean same = red1 == red2 && green1 == green2 && blue1 == blue2;
    
            // Write pixel is 'result' is the pixel is not the same
            if(!same)
               delta.setRGB(x, y, rgb1);
        }
    
    // Output
    final File out = new File(System.getProperty("user.home") + "/Desktop/delta.png");
    ImageIO.write(delta, "png", out);
```

  <img align="right" width="256" height="256" src="https://image.noelshack.com/fichiers/2018/05/6/1517674458-delta.png">
  
<center><br><br><br><br><br>The output image contains the code! -><br>
Here is the code: <b>3%67aa8d</b></center>

<br><br>
**Hope you enjoyed this example problem! 
<br>If you want others, Find The Solution website will be on soon!**
