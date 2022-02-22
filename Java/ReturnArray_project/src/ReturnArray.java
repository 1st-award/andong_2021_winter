public class ReturnArray {
	
	static int[] makeArray() {
		int[] temp = {1, 2, 3, 4};
		//int temp[] = new int[4];
		//for(int i = 0; i<temp.length; ++i) {
		//	temp[i] = i;
		//}
		return temp;
	}
	
	public static void main(String[] args) {
		int intArray[];
		intArray = makeArray();
		
		for(int num : intArray) {
			System.out.print(num + " ");
		}
	}
}
