import java.util.Scanner;

public class BMI {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("�� cm���� : ");
		int start = sc.nextInt();
		System.out.print("�� cm���� : ");
		int end = sc.nextInt();
		System.out.print("���� �� : ");
		int increase = sc.nextInt();
		
		showBMI(start, end, increase);				
	}
	
	public static void showBMI(int _start, int _end, int _increase) {
		System.out.println("����   ǥ��ü��");
		for(int i = _start; i <= _end; i+=_increase) {
			double bmi = (i - 100) * 0.9;
			System.out.println(i + " " + bmi);
		}
	}
}
