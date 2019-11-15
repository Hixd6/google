package sec2;
import java.util.Scanner;
import java.text.DecimalFormat;
abstract class shape {// 抽象类

    /* 抽象方法 求面积 */
    public abstract double getArea();

    /* 抽象方法 求周长 */
    public abstract double getPerimeter();
}
/* 你提交的代码将嵌入到这里 */ 
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
        DecimalFormat d = new DecimalFormat("#.####");// 保留4位小数
        int n=input.nextInt();
        double side = input.nextDouble();

        shape rp = new  RegularPolygon(n,side);

        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    }
}