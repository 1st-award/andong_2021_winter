import java.util.Scanner;

public class SumMul {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("������ : ");
		int num = sc.nextInt();
		int sum = calcMul(num);
		
		System.out.println("1���� " + num + "������ ���� "  + sum + "�Դϴ�.");
	}
	
	public static int calcMul(int _num) {
		int sum = 1;
		for(int i = 1; i <= _num; ++i) {
			sum *= i;
		}
		return sum;
	}
}
