
import java.net.*;
import java.io.*;
import java.time.ZonedDateTime;
/**
 *
 * @author benjamin
 */

class Handler extends Thread{
    Socket s;
    PrintWriter pw;
    BufferedReader br;
    String msg;
    
    void Set(Socket s){
        try {
            this.s = s;
            pw = new PrintWriter(s.getOutputStream(),true);
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            this.start();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void run() {
        super.run(); //To change body of generated methods, choose Tools | Templates.
        while(true){
            try {
                msg = br.readLine();
                System.out.println(s.getPort()+"  -> "+msg);
                if(msg ==  null){
                    break;
                }
                pw.println("ACK  "+ZonedDateTime.now());
            } catch (Exception e) {
                System.out.println(e.getMessage());
                break;
            }
        }
    }
    
    
}

public class Server {
    public static void main(String[] args) {
        System.out.println("Server");
        ServerSocket ss;
        try {
            ss = new ServerSocket(10024);
            while(true){
                Handler obj = new Handler();
                Socket s = ss.accept();
                obj.Set(s);                
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
