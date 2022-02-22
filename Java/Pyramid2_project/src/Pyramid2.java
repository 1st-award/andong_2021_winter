import java.util.Scanner;

public class Pyramid2 {
	static void showPyramid(int _height) {
		for(int i = 0; i < _height; ++i) {
			for(int j = _height-2-i; j >= 0; --j) {
				System.out.print(" ");
			}
			for(int k = 0; k < i*2+1; ++k) {
				System.out.printf("%d", i+1);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("높이 입력 : ");
		int height = sc.nextInt();
		showPyramid(height);
	}
}
