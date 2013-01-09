/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Kyong-Tae
 */
import java.util.*;
        
public class Checker {
    boolean valid = false;
    List<String> validWords = new ArrayList<String>();
    
    public boolean checkWord(String word){
        if (validWords.contains(word)){
                return true;
            }
            else return false;
        }
    }
    //public void checkFile(String file)
    
