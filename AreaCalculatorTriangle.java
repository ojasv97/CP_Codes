import java.util.Scanner;
public class AreaCalculatorTriangle
{
	public static void main(String[] p)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length of 1st side :");
		int a = sc.nextInt();
		System.out.println("Enter the length of 2nd side :");
		int b = sc.nextInt();
		System.out.println("Enter the length of 3rd side :");
		int c = sc.nextInt();
		double s = (a+b+c)/2;
		double area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
		System.out.println("Area = "+area);
	}
}