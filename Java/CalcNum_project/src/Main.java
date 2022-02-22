import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("입력받을정수의 개수? : ");
		int length = sc.nextInt();
		
		int[] arr = new int[length];
		for(int i = 0; i<length; ++i) {
			System.out.print("정수 : ");
			arr[i] = sc.nextInt();
		}
		
		Calc c = new Calc(arr, length);
		System.out.printf("%d개의 정수의 합계는 %d이며 평균은 %.2f입니다.\n", c.length, c.getSum(), c.getMean());
	}
}
