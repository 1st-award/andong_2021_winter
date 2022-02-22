import java.util.Scanner;

public class RenewalCalcSum {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Á¤¼ý°ª : ");
		int num = sc.nextInt();
		
		showCalcSum(num);
		
	}
	
	public static void showCalcSum(int _num) {
		int sum = 0;
		for(int i = 1; i<=_num; ++i) {
			System.out.print(i);
			if(i != _num)
				System.out.print(" + ");
			sum +=i;
		}
		System.out.print(" = "  + sum);
	}
}
