import java.util.Scanner;

public class CountUp {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Á¤¼ö°ª : ");
		int num = sc.nextInt();
		
		showCountUp(num);
	}
	
	public static void showCountUp(int _num) {
		for(int i = 0; i<=_num; ++i) {
			System.out.print(i  +" ");
		}
	}
}
