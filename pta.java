package sec2;
import java.util.Scanner;
import java.text.DecimalFormat;
abstract class shape {// ������

    /* ���󷽷� ����� */
    public abstract double getArea();

    /* ���󷽷� ���ܳ� */
    public abstract double getPerimeter();
}
/* ���ύ�Ĵ��뽫Ƕ�뵽���� */ 
class RegularPolygon extends shape{
	public double getArea() {
		return 1.0;
	}
	public double getPerimeter(){
		return 1.0;
	}
	public RegularPolygon(int n,double side)
	{
		
	}
}
public class pta {
  public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");// ����4λС��
        int n=input.nextInt();
        double side = input.nextDouble();

        shape rp = new  RegularPolygon(n,side);

        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    }
}