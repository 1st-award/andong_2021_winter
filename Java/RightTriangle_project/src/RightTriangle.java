import java.util.Scanner; 

public class RightTriangle {
	static void showRightTriangle(int _height) {
		for(int i = 0; i<_height; ++i) {
			for(int j = i; j<_height-1; ++j) {
				System.out.print(" ");
			}
			for(int k = 0; k <= i; ++k) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("높이 입력 : ");
		int height = sc.nextInt();
		
		showRightTriangle(height);
	}
}
