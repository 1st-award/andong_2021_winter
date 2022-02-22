public class Main {
	public static void main(String[] args) {
		Circle pizza = new Circle(10, "자바피자");
		double area = pizza.getArea();
		System.out.println(pizza.name + "의 면적은 " + area);
		
		Circle donut = new Circle();
		donut.name = "자바도넛";
		area = donut.getArea();
		System.out.println(donut.name + "의 면적은 " + area);
	}
}
