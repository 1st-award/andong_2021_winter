import java.util.Scanner;

public class CalcSum {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("������ : ");
		int num = sc.nextInt();
		int sum = calcSum(num);
		
		System.out.println(num + "������ ���� " + sum + "�Դϴ�.");
	}
	
	public static int calcSum(int _num) {
		int sum = 0;
		for(int i = 1; i<=_num; ++i) {
			sum +=i;
		}
		
		return sum;
	}
}
