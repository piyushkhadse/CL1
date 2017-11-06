import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;


public class tfIdf {

	static List<HashMap<String, Float>> tf = new ArrayList<HashMap<String, Float>>();
	static HashMap<String, Float> idf = new HashMap<String, Float>();
	static String wordDoc[][];
	static int numD;
	
	public static void main(String[] args){
		try{
			File file = new File("/home/student/inputTF.txt");
			String data, doc[] = new String[10];
			wordDoc = new String[10][100];
			  
			numD = 0;
			BufferedReader br = new BufferedReader(new FileReader(file));
			System.out.println("Documents are: ");
			while((data=br.readLine())!=null){
				System.out.println("Document[" + numD + "]: " + data);
				doc[numD++] = data;
			}
			br.close();
			
			for(int i = 0; i < numD; i++){
				wordDoc[i]=doc[i].split(" ");
			}
			
			//calculate normalized tf
			for(int i = 0; i < numD; i++){
				HashMap<String, Float> temp = new HashMap<String, Float>();
				for(int j = 0; j < wordDoc[i].length; j++){
					if(temp.containsKey(wordDoc[i][j]))
						temp.put(wordDoc[i][j], temp.get(wordDoc[i][j])+1);
					else
						temp.put(wordDoc[i][j], (float)1);
				}
				for( String key : temp.keySet() ){
					temp.put(key, temp.get(key)/wordDoc[i].length);
				}
				tf.add(temp);
			}
			
			System.out.println("\nNormalized TF values for each document are:");
			for(int i=0; i<tf.size(); i++)
				System.out.println("Document[" + i + "]: " + Arrays.asList("" + tf.get(i)));
			
			//calculate idf
			for(int i = 0; i < numD; i++){
				for(int j = 0; j < wordDoc[i].length; j++){
					if(!idf.containsKey(wordDoc[i][j]))
						idf.put(wordDoc[i][j], (float)0);
				}
			}
			for( String key : idf.keySet() ){
				for(int i = 0; i < numD; i++){
					for(int j = 0; j < wordDoc[i].length; j++){
						if(key.equals(wordDoc[i][j])){
							idf.put(key, idf.get(key)+1);
							break;
						}
					}
				}
				idf.put(key, 1 + (float)Math.log(numD/idf.get(key)));
			}
			
			System.out.println("\nIDF values for each key are:");
			System.out.println(Arrays.asList("" + idf));	
		
			System.out.print("\nEnter Query:");
			BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			String query = br1.readLine();
			String queryKeySet[] = new String[query.split(" ").length];
			queryKeySet = query.split(" ");
			float tfIdfValues[][] = new float[queryKeySet.length][numD];
			
			//calculate tf * idf values for all documents
			System.out.print("\n(TF * IDF) values for each key of query are:\n"+ String.format("%10s", "Keys") + "\t");
			
			for(int i = 0; i< numD; i++)
				System.out.print("Document " + i + "\t");
			
			for(int i = 0; i < queryKeySet.length; i++){
				System.out.print("\n" + String.format("%10s", queryKeySet[i]) );
				for(int j = 0; j < numD; j++){
					if(tf.get(j).get(queryKeySet[i]) != null && idf.get(queryKeySet[i]) != null)
						tfIdfValues[i][j] = tf.get(j).get(queryKeySet[i]) * idf.get(queryKeySet[i]);
					else
						tfIdfValues[i][j] = (float)0;
					System.out.print("\t" + String.format("%10f", tfIdfValues[i][j]));
				}
			}
			
			HashMap<String, Float> queryTfIdf = new HashMap<String, Float>();
			//calculate tf for query
			for(int j = 0; j < queryKeySet.length; j++){
				if(queryTfIdf.containsKey(queryKeySet[j]))
					queryTfIdf.put(queryKeySet[j], queryTfIdf.get(queryKeySet[j])+1);
				else
					queryTfIdf.put(queryKeySet[j], (float)1);
			}
			
			//calulate tf * idf for query
			System.out.println("\n\n(TF * IDF) values for query as a document are:");
			
			for( String key : queryTfIdf.keySet() ){
				System.out.print( String.format("%10s", key) + "\t");
				queryTfIdf.put(key, queryTfIdf.get(key)/queryKeySet.length);
				if(idf.get(key)!=null)
					queryTfIdf.put(key, queryTfIdf.get(key) * idf.get(key));
				else
					queryTfIdf.put(key, (float)0);
				System.out.println(queryTfIdf.get(key));
			}
			
			
			float cosineSimilarity[] = new float[numD];
			float dotProduct, rmsQuery, rmsDoc;
			System.out.println("\nRanks of Documents using Cosine Similarity for given query are:");
			for(int i = 0; i < numD; i++){
				dotProduct = (float)0; 
				rmsQuery = (float)0;
				rmsDoc = (float)0;
				for(int j = 0; j < queryKeySet.length; j++){
					dotProduct += tfIdfValues[j][i] * queryTfIdf.get(queryKeySet[j]);
					rmsQuery += (float)Math.pow(queryTfIdf.get(queryKeySet[j]), 2);
					rmsDoc += (float)Math.pow(tfIdfValues[j][i], 2);
				}
				rmsQuery = (float)Math.sqrt(rmsQuery);
				rmsDoc = (float)Math.sqrt(rmsDoc);
				
				if(dotProduct == 0 || rmsQuery == 0 || rmsDoc ==0)
					cosineSimilarity[i] = (float)0;
				else
					cosineSimilarity[i] = dotProduct / (rmsQuery * rmsDoc);
				
				System.out.println("Document["+ i + "]: " + cosineSimilarity[i]);
			}			
		} catch(Exception e){
			e.printStackTrace();
		}
		
	}
}

/* OUTPUT

student@B4L0106:~$ javac tfIdf.java
student@B4L0106:~$ java tfIdf 
Documents are: 
Document[0]: The game of life is a game of everlasting learning
Document[1]: The unexamined life is not worth living
Document[2]: Never stop learning

Normalized TF values for each document are:
Document[0]: [{of=0.2, The=0.1, is=0.1, life=0.1, a=0.1, learning=0.1, game=0.2, everlasting=0.1}]
Document[1]: [{not=0.14285715, The=0.14285715, is=0.14285715, life=0.14285715, unexamined=0.14285715, living=0.14285715, worth=0.14285715}]
Document[2]: [{stop=0.33333334, Never=0.33333334, learning=0.33333334}]

IDF values for each key are:
[{stop=2.0986123, is=1.4054651, Never=2.0986123, a=2.0986123, game=2.0986123, learning=1.4054651, unexamined=2.0986123, living=2.0986123, everlasting=2.0986123, not=2.0986123, The=1.4054651, of=2.0986123, life=1.4054651, worth=2.0986123}]

Enter Query:life learning

(TF * IDF) values for each key of query are:
      Keys	Document 0	Document 1	Document 2	
      life	  0.140547	  0.200781	  0.000000
  learning	  0.140547	  0.000000	  0.468488

(TF * IDF) values for query as a document are:
      life	0.70273256
  learning	0.70273256

Ranks of Documents using Cosine Similarity for given query are:
Document[0]: 0.99999994
Document[1]: 0.70710677
Document[2]: 0.70710677
student@B4L0106:~$ 

*/
