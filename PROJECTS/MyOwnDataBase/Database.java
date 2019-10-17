import java.util.*;
import java.io.*;
import java.lang.*;
import command.*;
public class Database
{
    public static void main(String ar[])throws IOException
    {
        System.out.println("Only for create,insert,select,drop,load,print");
        Scanner sc=new Scanner(System.in);
        ArrayList<ArrayList<String>>alist=new ArrayList<ArrayList<String>>();
        while(true)
        {
        String str=sc.nextLine();
        if(str.equals("EXIT")||str.equals("QUIT"))
            System.exit(0);
        str=str.trim().replaceAll("\\s{1,}"," ");
        str=str.toLowerCase();
        String comm[]=str.split(" ");
        if(comm[0].equals("load")||comm[0].equals("print"))
        {
            switch(comm[0])
            {
              case "load":
                    Load ld=new Load();
                    ld.load(comm,alist);
                    break;
               case "print":
                    Print pr=new Print();
                    pr.print(comm,alist);
                    break;       
            }
        }
       else if(comm.length<3)
            System.out.println("Less number of argument is passed");
        else
        {
        switch(comm[0])
        {
            case "create":
                Create cr=new Create();
                cr.create(comm,str);
                break;
            case "select":
                Select sl=new Select();
                sl.select(comm,str);
                break;
            case "insert":
                Insert ins=new Insert();
                ins.insert(comm,str);
                break;
            case "update":
                break;
            case "drop":
                Drop dp=new Drop();
                dp.drop(comm,str);
                break;
            default:
                System.out.println("command not recognised");
        }
        }
        }
    }
}
