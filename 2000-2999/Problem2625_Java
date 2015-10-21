import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;

public class Main {

	public static void main(String[] args) throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		StringBuffer sb = new StringBuffer("");
		String m = "";
		int num = Integer.parseInt(br.readLine());
		for (int i = 0; i < num; i++) {
			BigDecimal bd = BigDecimal.ZERO;
			while (true) {
				BigDecimal bd2 = new BigDecimal(br.readLine());
				if (bd2.compareTo(BigDecimal.ZERO) == 0) break;
				bd = bd.add(bd2);
			}
			sb.append(trail(bd)).append("\n");
		}
		System.out.print(sb);
	}

		static String trail(BigDecimal bd){
		String ans = bd.toString();
		if (ans.indexOf('.') != -1) {
			int lenOfSubString = ans.length() - 1;
			while (ans.charAt(lenOfSubString) == '0') lenOfSubString--;
			if (ans.charAt(lenOfSubString) == '.') ans = ans.substring(0, lenOfSubString);
			else ans = ans.substring(0, lenOfSubString + 1);
		}
		return ans;
	}
}
