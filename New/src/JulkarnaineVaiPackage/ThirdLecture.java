package JulkarnaineVaiPackage;

import java.util.Objects;

public class ThirdLecture {
    public static void main(String[] args) {

        String name= new String("Tangail Dhaka");
        String s1="Karim Molla";
        System.out.println(name);

        //System.out.println(s1);
        printLine(s1);
        printLine("I am a Cricketer");
        printLine(10+20);
        printLine(45.67-20.67);
        printLine('r');
        printLine(false);
        printLine("bangla"+"english");
    }

    public static void printLine(Object anyobject){
        System.out.println(anyobject);
    }
}
