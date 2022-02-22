public class Calc {
	int[] num;
	int length;
	
	public Calc(int[] _num, int length) {
		num = _num;
		this.length = length;
	}
	
	public int getSum() {
		int sum = 0; 
		for(int i : num) {
			sum += i;
		}
		return sum;
	}
	
	public double getMean() {
		return getSum() / (double)length;
	}
}
