using System;
using System.Drawing;
using System.IO;

class ImageConverter
{
	static void Main(string[] INPUT)
	{
		//set output path
		string filePath = @"MatrixOutput\";
		string fileName = INPUT[0];
		fileName=fileName.Remove(fileName.Length-3);
		fileName+="txt";
		filePath+=fileName;
		
		Console.WriteLine(filePath);
		try
		{
			Bitmap bmp = new Bitmap(Image.FromFile(INPUT[0]));
			
			//Prevent appending results to the end of an already existing text file
			if(File.Exists(filePath))
			{
				Console.WriteLine("\nThe specefied output path already exists.");
				return;
			}
			
			Convert(bmp, filePath);
		}
		catch (Exception)
		{
			Console.WriteLine("An error occured.");
			return;
		}
		Console.WriteLine("\nOperation completed successfully!");
	}
	
	static void Convert(Bitmap INPUTBMP, string OUTPUTPATH)
	{
		using (StreamWriter output = new StreamWriter(OUTPUTPATH, true))
		{
			output.WriteLine("Converted Output:");
			output.WriteLine("{");
			for(int y = 0; y<=15; y++)
			{
				output.Write("{");
				for(int x = 0; x<=31; x++)
				{
					Color pixel = INPUTBMP.GetPixel(x,y);
					Console.WriteLine(pixel);
					
					if(pixel.R == 0 && pixel.G == 0 && pixel.B == 0)
					{
						//BLACK
						output.Write("0");
					}
					
					else if(pixel.R == 255 && pixel.G == 0 && pixel.B == 0)
					{
						//RED
						output.Write("1");
					}
						
					else if(pixel.R == 0 && pixel.G == 255 && pixel.B == 0)
					{
						//GREEN
						output.Write("2");
					}
						
					else if(pixel.R == 255 && pixel.G == 255 && pixel.B == 0)
					{
						//YELLOW
						output.Write("3");
					}
						
					else if(pixel.R == 0 && pixel.G == 0 && pixel.B == 255)
					{
						//BLUE
						output.Write("4");
					}
				
					else if(pixel.R == 255 && pixel.G == 0 && pixel.B == 255)
					{
						//PURPLE
						output.Write("5");
					}
						
					else if(pixel.R == 0 && pixel.G == 255 && pixel.B == 255)
					{
						//CYAN
						output.Write("6");
					}
					
					else if(pixel.R == 255 && pixel.G == 255 && pixel.B == 255)
					{
						//WHITE
						output.Write("7");
					}
								
								
					if(x < 31)
						output.Write(",");
				}
			if (y == 15)
				output.WriteLine("}");
			else
				output.WriteLine("},");
			}	
		output.Write("};");
		}
	}
}