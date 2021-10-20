import java.util.Scanner;
public class AreaCalculator
{
	public static void main(String[] s)
	{
		System.out.println("Enter the length and the width of a rectangle :");
		Scanner sc = new Scanner(System.in);
		int length = sc.nextInt();
		int width = sc.nextInt();
		int area = length*width;
		int perimeter  = 2*(length+width);
		System.out.println("Area = "+area);
		System.out.println("Perimeter = "+perimeter);
	}
}