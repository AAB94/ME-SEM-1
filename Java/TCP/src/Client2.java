/**
 *
 * @author benjamin
 */
import java.io.*;
import java.net.*;
import java.util.Scanner;
public class Client2 {
    Socket s;
    PrintWriter pw;
    BufferedReader br;
    String msg;
    
    public void Set(){
        try{
            s = new Socket(InetAddress.getLocalHost(),10024);
            pw = new PrintWriter(s.getOutputStream(),true);
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            Thread t = new Thread(new Runnable() {
                @Override
                public void run()  {
                    try{
                        while(true){
                            msg = br.readLine();
                            System.out.println(msg);
                            if(msg == null){
                                br.close();
                                pw.close();
                                s.close();
                                System.exit(0);
                            }
                        }
                    }catch(Exception e){
                        System.out.println(e.getMessage());
                    }
                }
            });
            t.start();
        } catch(Exception E){
            System.out.println(E.getMessage());
        }
    }
    
    public void Send(){
       try {
            
            Scanner in = new Scanner(System.in);
            while(true){
                System.out.println("Enter Message");
                pw.println(in.nextLine());
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } 
    }
    
    public static void main(String[] args) {
        System.out.println("Client");
        Client2 c = new Client2();
        c.Set();
        c.Send();
    }
}
