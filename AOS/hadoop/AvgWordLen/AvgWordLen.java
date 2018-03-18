import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.FloatWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class AvgWordLen {
	public static class TokenizerMapper extends Mapper<Object, Text, IntWritable, IntWritable>{
	


	private final static IntWritable one = new IntWritable(1);
	

	public void map(Object key, Text value, Context context) throws IOException, InterruptedException {
		context.write(one, new IntWritable(value.toString().length()));		
	}
}

// before reduce phase all the pairs with same keys are brought
// together or they are shuffeled and arranged, so that they can be
// worked upon as a group
public static class IntSumReducer extends Reducer<IntWritable,IntWritable,Text,FloatWritable> {


		public void reduce(IntWritable key, Iterable<IntWritable> values,Context context) throws IOException, InterruptedException {
			float sum = 0;
			float count = 0;
			for (IntWritable val : values) {
				sum += val.get();
				++count;
			}
			sum = sum/count;
			context.write(new Text("Average Length of Strings"), new FloatWritable(sum));
		}
	}
	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf, "Avg Word Len");
		job.setJarByClass(AvgWordLen.class);
		job.setMapperClass(TokenizerMapper.class);
		
		job.setMapOutputKeyClass(IntWritable.class);
		job.setMapOutputValueClass(IntWritable.class);
		
		
		job.setReducerClass(IntSumReducer.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(FloatWritable.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}
