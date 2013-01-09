/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Kyong-Tae
 */
import java.util.*;
import java.io.*;
        
public class Checker{
    boolean valid = false;
    List<String> validWords = new ArrayList<String>();
    String locDictionary = "dictionary.txt";
    
    public boolean checkWord(String word){
        if (validWords.contains(word)){
                return true;
            }
            else return false;
        }
    public boolean checkWordToFile(String word){
        try {
            BufferedReader br = new BufferedReader(new FileReader(locDictionary));
            String dictionaryWord = br.readLine();
            while(dictionaryWord != null){
                if (word.equals(dictionaryWord)){
                    return true;
                }
            }
            br.close();
        }
        catch (IOException e){
            System.out.println("Excetption: " + e.getMessage());
        }
        return false;
    }
    
    public void checkFile(String file){
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            String permutedWord = br.readLine();
            List<String> permutedWords = new ArrayList<String>();
            while(permutedWord != null){
                permutedWords.add(permutedWord);
            }
            br.close();
            for(int i = 0; i < permutedWords.size(); i++){
                if(checkWordToFile(permutedWords.get(i)) == true){
                    validWords.add(permutedWords.get(i));
                }
            }
        }
        catch (IOException e){
            System.out.println("Excetption: " + e.getMessage());
        }
}
    public void removeWords(){
        validWords.clear();
    }
}
    
