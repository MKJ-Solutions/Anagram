public class Permutator{
    public String permute(String letters){
        String result = "";
        String usedPrefix = "";
        if (letters.length() == 1){
            return letters;
        }
        else{
            
            for (int i = 0; i < letters.length(); i++){
                String permuted = "";
                String prefix = letters.substring(i,i+1);
                String rest = letters.substring(0,i)+letters.substring(i+1);
                if (usedPrefix.contains(prefix)==false){
                    permuted = permuted + prefix + permute(rest);
                    String fixed = "";
                    int numIteration = (permuted.length()-1)/rest.length()+1;
                    for (int j = 1; j < numIteration; j++){
                        fixed += prefix + permuted.substring(1+rest.length()*(j-1),1+rest.length()*j);
                    }
                    result += fixed;
                }
                usedPrefix += prefix;
            }return result;
        }
    }
    
    public void display(String letters){
        String result = permute(letters);
        int numPermutations = result.length()/letters.length();
        for (int i = 0; i < numPermutations; i++){
            int begin = letters.length()*i;
            int end = letters.length()*(i+1);
            System.out.println((i+1)+". "+result.substring(begin, end));
        }
    }
}