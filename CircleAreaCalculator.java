import java.util.Scanner;
public class CircleAreaCalculator {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter vthe diameter of a circle :");
        double diameter=sc.nextDouble();
        double area=3.14*(diameter/2)*(diameter/2);
        double circumference=3.14*diameter;
        System.out.println("Area="+area);
        
        DecimalFormat df=new DecimalFormat("###.##");
        System.out.println("Circumference="+df.format(circumference));
        
        
    }
}
