import java.util.Scanner;

public class ShowIntLength {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		showLength(num);
	}
	
	public static void showLength(int num) {
		int count = 0;
		while(num!=0) {
			num /= 10;
			++count;
		}
		
		System.out.println("이 값은 " + count + "자릿수 입니다.");
	}
}
