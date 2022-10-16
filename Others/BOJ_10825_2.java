//조건 변형
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	static class Student { // Student 구조체를 정의합니다
		String name;
		int kor;
		int eng;

		public Student(String name,int kor,int eng) {
			this.name = name;
			this.kor = kor;
			this.eng = eng;
		}
	}
    public static ArrayList<String> solution(int N, String [] name, int [] kor, int [] eng){
    	ArrayList <String> answer = new ArrayList<>();
      ArrayList <Student> list = new ArrayList<>(); // Student들을 담을 ArrayList를 생성합니다
    	for(int i = 0; i < N; i++) {
			list.add(new Student(name[i],kor[i],eng[i])); 
		}
    	Collections.sort(list,new Comparator<Student>() { // 정렬합니다
			@Override
			public int compare(Student o1, Student o2) {
				if(o1.kor==o2.kor) {
					if(o1.eng==o2.eng) {
							return o1.name.compareTo(o2.name);
					}return o2.eng-o1.eng;
				}else
					return o1.kor-o2.kor;
			}
		});
    	for(Student s : list) answer.add(s.name);
    	return answer;
    }
	public static void main(String[] args){
	  Scanner sc = new Scanner(System.in);
	  StringBuilder sb = new StringBuilder();
		int N = sc.nextInt();
		String [] name = new String[100010];
		int [] kor = new int [100010];
		int [] eng = new int [100010];

		for(int i = 0; i < N; i++) {
			name[i] = sc.next();
			kor[i] = sc.nextInt();
			eng[i] = sc.nextInt();
		}
		ArrayList<String> answer = solution(N,name,kor,eng);
		for(String s : answer) sb.append(s).append("\n");
		System.out.print(sb);
		sc.close();
	}
}