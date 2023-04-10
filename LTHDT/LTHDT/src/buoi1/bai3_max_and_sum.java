package buoi1;

public class bai3_max_and_sum {
	public static void main(String[] args) {
		double tong = 0, n = 0;
		for(String s: args) {
			try {
				n = Double.parseDouble(s);
			}
			catch(NumberFormatException e) {
				n = 0;
			}
			tong += n;
		}
		System.out.println("Tong = "+ tong);
	}
}
