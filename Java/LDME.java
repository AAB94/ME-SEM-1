
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author benjamin
 */


/**
 *  Message Request
 * 
 */

class Message implements Comparable<Message>{
    int sid; //  Site ID
    int ts; //TimeStamp
    
    public Message(int sid,int ts){
        this.sid = sid;
        this.ts = ts;
    }

    @Override
    public int compareTo(Message o) {
        return ts - o.ts;
    }
    
}


class Site {
    int sid;
    ArrayList<Message> reqq = new ArrayList<Message>(); //request queue
    int SIZE = 3;
    int reqts; //request time stamp
    int sset[] = new int[SIZE - 1]; 
    int reply;
    boolean release = false; //When value becomes true indicates release message being received   
}



public class LDME {
    final int N = 3; //No of Processes
    Site s[] = new Site[N];
    public void Set(){
        int i,j = 0,k;
        
        int perm[][] = {{0,1,2},{0,2,1},{2,1,0},{2,0,1},{1,0,2},{1,2,0}};
        
        for( i = 0; i < N; ++i){
            s[i] = new Site();
            s[i].sid = i;
            k = 0;
            for(j = 0; j < 3; ++j){
                if( j != s[i].sid){
                    s[i].sset[k] = j;
                    ++k;
                }
            }
        }
        
        
        Random rand = new Random();
        /**
         * Select randomly which site will Request CS first
         * Assigning Time stamp to Sites at random
         */
        k = rand.nextInt(6);
        for( i = 0; i < N; ++i){
            j = rand.nextInt(20+j) + 1 + j;
            s[perm[k][i]].reqts = j;
        }
    }
    
    public void Execute(Site x){
        x.reqq.add(new Message(x.sid,x.reqts));
        int i;
        boolean flag = false;
        for( i = 0; i < N;++i){
            if(x.sid != i){
                s[i].reqq.add(new Message(x.sid,x.reqts));
                s[i].reply += 1;
            }
        }
        try{Thread.sleep(800);}catch(Exception e){}
        
        Collections.sort(x.reqq);
        
        while(true){
            Collections.sort(x.reqq);
            Release(x);
            
            if( ( x.reply == 2 ) && ( x.reqq.get(0).sid == x.sid ) ){
                System.out.println("--------------------------------------------------------------------------");
                System.out.println("**\tSite Queue\t**");
                System.out.print("\t");
                for( i = 0; i < x.reqq.size(); ++i)
                    System.out.print("( S"+x.reqq.get(i).sid+" ,"+x.reqq.get(i).ts+" ), ");
                System.out.println("");
                System.out.println("Site  S"+x.reqq.get(0).sid+" Working in Critical Section....");
                try{Thread.sleep(1500);}catch(Exception e){}
                System.out.println("Site  S"+x.reqq.get(0).sid+" Work Completed");
                
                System.out.println("--------------------------------------------------------------------------");
                try{Thread.sleep(1200);}catch(Exception e){}
                x.reqq.remove(0);
                break;
            }
            
        }
        
        for(int y : x.sset)
            s[y].release = true;
            
        
    }
    
        
    public synchronized void Release(Site x){
        if(x.release){
            
            x.reqq.remove(0);
            x.release = false;
        }
    }
    
    public void Begin(){
        Set();
        
        Thread p0 = new Thread(new Runnable() {
            @Override
            public void run() {
                Execute(s[0]);
            }
        });
        
        Thread p1 = new Thread(new Runnable() {
            @Override
            public void run() {
                Execute(s[1]);
            }
        });
        
        Thread p2 = new Thread(new Runnable() {
            @Override
            public void run() { 
                Execute(s[2]);
            }
        });
        try{
            p0.start();
            p1.start();
            p2.start();
            
        }
        catch(Exception E){
            E.getStackTrace();
            System.exit(1);
        }
    }
    
    public static void main(String[] args) {
        LDME obj = new LDME();
        obj.Begin();
    }
}