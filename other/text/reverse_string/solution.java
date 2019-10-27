import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// Ah Java, you and your verbosity. At least you handle unicode well.

public class solution {
    public static void main(String[] args) {
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String input = br.readLine();
            System.out.println(new StringBuilder(input).reverse().toString());
        }catch(IOException io){
            io.printStackTrace();
        }
    }
}
