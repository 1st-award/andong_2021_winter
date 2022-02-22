import java.util.Scanner;

public class CalcSum {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("정숫값 : ");
		int num = sc.nextInt();
		int sum = calcSum(num);
		
		System.out.println(num + "까지의 합은 " + sum + "입니다.");
	}
	
	public static int calcSum(int _num) {
		int sum = 0;
		for(int i = 1; i<=_num; ++i) {
			sum +=i;
		}
		
		return sum;
	}
}
