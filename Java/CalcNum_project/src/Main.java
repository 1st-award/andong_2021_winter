import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("�Է¹��������� ����? : ");
		int length = sc.nextInt();
		
		int[] arr = new int[length];
		for(int i = 0; i<length; ++i) {
			System.out.print("���� : ");
			arr[i] = sc.nextInt();
		}
		
		Calc c = new Calc(arr, length);
		System.out.printf("%d���� ������ �հ�� %d�̸� ����� %.2f�Դϴ�.\n", c.length, c.getSum(), c.getMean());
	}
}
