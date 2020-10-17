import java.util.Scanner;
public class Hello{
    public static void main(String[] args){
        final int MAXINT = 199999;
        while(true){
            Scanner input=new Scanner(System.in);
            double radius=input.nextDouble();
            double area;
            area=3.14159 * radius * radius;
            System.out.println("\nHello World ------>"+area);
        }
    }
}