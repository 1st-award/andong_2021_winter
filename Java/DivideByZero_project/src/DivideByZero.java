import java.util.Scanner;

public class DivideByZero {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int dividend;	// 나뉨수
		int divisor;	// 나눗수
		
		while(true) {
			System.out.print("나뉨수를 입력하시오: ");
			dividend = sc.nextInt();
			System.out.print("나눗수를 입력하시오: ");
			divisor = sc.nextInt();
			try {
				System.out.println(dividend  +"를 " + divisor + "로 나누면 몫은 " + dividend/divisor + "입니다.");
				break;
			} catch(Exception e) {
				System.out.println("0으로 나눌 수없습니다! 다시 입력하세요");
			}
		}
	}
}
