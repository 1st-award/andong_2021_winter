import java.util.Scanner;

public class DivideByZero {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int dividend;	// ������
		int divisor;	// ������
		
		while(true) {
			System.out.print("�������� �Է��Ͻÿ�: ");
			dividend = sc.nextInt();
			System.out.print("�������� �Է��Ͻÿ�: ");
			divisor = sc.nextInt();
			try {
				System.out.println(dividend  +"�� " + divisor + "�� ������ ���� " + dividend/divisor + "�Դϴ�.");
				break;
			} catch(Exception e) {
				System.out.println("0���� ���� �������ϴ�! �ٽ� �Է��ϼ���");
			}
		}
	}
}
