//import java.util.*;
class Test{
    public static void main(String[] args){
        //Permutator permute = new Permutator();
        //String letters = "aaab";
        //permute.display(letters);
        Checker check = new Checker();
        String word = "abc";
        //check.validWords.add(word);
        if (check.checkWord(word)){
            System.out.print("haha");
        }
        else System.out.print("damn");
    }
}