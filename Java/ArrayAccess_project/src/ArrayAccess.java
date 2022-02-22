import java.util.Scanner;

public class ArrayAccess {
	
	public static void main(String[] args) {
		int []intArray = new int[5];
		ArrayAccess.setArray(intArray);
		int max = ArrayAccess.getMax(intArray);
		System.out.println("가장 큰 수는 " + max + "입니다");
	}
	
	
	public static void setArray(int[] _array) {
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i<5; ++i) {
			_array[i] = sc.nextInt();
		}
		sc.close();
	}
	
	public static int getMax(int[] _array) {
		int max = _array[0];
		
		for(int i = 1; i< 5; ++i) {
			if(max < _array[i]) {
				max = _array[i];
			}
		}
		
		return max;
	}
}
