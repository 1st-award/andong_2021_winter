import java.util.Scanner;

public class ArrayLength {
	public static void main(String[] args) {
		int intArray[] = new int[5];
		setArray(intArray);
		int sum = getSum(intArray);
		double mean = getMean(sum, intArray.length);
		
		System.out.println("∆Ú±’¿∫ " + mean);
	}
	
	public static void setArray(int[] _array) {
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < _array.length; ++i) {
			_array[i] = sc.nextInt();
		}
		sc.close();
	}
	
	public static int getSum(int[] _array) {
		int sum = 0;
		for(int value : _array) {
			sum += value;
		}
		return sum;
	}
	
	public static double getMean(int _sum, int _length) {
		return (double)_sum / _length;
	}
}
