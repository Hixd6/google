import java.util.Scanner;
import java.math.*;
public class sec {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter three points for a triangle:");
		float a[];
		a = new float[3];
		float b[];
		b = new float[3];
		for(int i = 0;i<3;i++)
		{
			a[i] = sc.nextFloat;
			b[i] = sc.netFloat;	
		}
		float side[];
		side = new float[3]; 
		float side1,side2,side3;
		for(int j = 0;j<2;j++)
		{
			side[j]=Math.pow((a[j+1]-a[j]),2)+pow((b[j+1]-b[j]),2);
		}
		side[2] =Math.pow((a[2]-a[0]),2)+pow((b[2]-b[0]),2);
		float s;
		s=(side[1]+side[2]+side[0])/2;
		float half = s*(s - side[0])*(s - side[1])*(s - side[2]);
		float area = Math.pow((half),2);
		System.out.println("The area of the triangle is"+area);

	}
}