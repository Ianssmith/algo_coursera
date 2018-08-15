#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::make_pair;

class JobQueue {
	private:
		long long num_workers_;
		vector<long long> jobs_;
		vector<long long> worker_timer_;
		vector<std::pair<long long,long long>> worker_queue;
		int previous_thread = 0;

		vector<int> assigned_workers_;
		vector<long long> start_times_;

		void WriteResponse() const {
			for (int i = 0; i < jobs_.size(); ++i) {
				cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
			}
		}

		void ReadData() {
			int m;
			cin >> num_workers_ >> m;
			jobs_.resize(m);
			for(int i = 0; i < m; ++i)
				cin >> jobs_[i];
			//worker_queue.resize(num_workers_);
			worker_timer_.resize(num_workers_);
		}



		void siftup(int i){
			while(i>1 && worker_queue[i/2].second > worker_queue[i].second){
				swap(worker_queue[i/2], worker_queue[i]);
				i = i/2;
			}
		}

		std::pair<long long,long long> getmin(){
			return worker_queue[0];
		}

		void change_priority(int i,long long p, bool recurse ){
			//long long oldp = worker_queue[i].second;
			if(!recurse){
				worker_queue[i].second += p;
			}
			//if(i+1 < worker_queue.size() && worker_queue[i].
				siftdown(i);
		}

		void siftdown(int i ){
			//int sibling = NULL;
			//if(i > 0 && i+1 < worker_queue.size())
				//int sibling = i+1;
			int minIndex = i;
			int l = (2*i)+1;
			int r = (2*i)+2;
			if(l < worker_queue.size() && worker_queue[l].second <= worker_queue[minIndex].second){
				swap(worker_queue[i], worker_queue[l]);
				minIndex = l;
				change_priority(minIndex,worker_queue[minIndex].second,true);
			}
			if(r < worker_queue.size() && worker_queue[r].second <= worker_queue[minIndex].second){
				swap(worker_queue[minIndex], worker_queue[r]);
				minIndex = r;
				change_priority(minIndex,worker_queue[minIndex].second,true);
			}
			/*
			if(minIndex != i){
				//swap(worker_queue[i], worker_queue[minIndex]);
				change_priority(minIndex,worker_queue[minIndex].second,true);
			}
			else
			{
				for(int j=minIndex;j<worker_queue.size()-1;j++){
					swap(worker_queue[j],worker_queue[j+1]);
					change_priority(j+1,worker_queue[j+1].second,true);
				}
			}
			*/

			
			/*
			 if(l < worker_queue.size()){
			    if(sibling){
			    	swap(worker_queue[minIndex],worker_queue[sibling]);
			    	swap(worker_queue[sibling],worker_queue[l]);
					minIndex = l;
					if(r< worker_queue.size()){
						swap(worker_queue[l],worker_queue[r]);
						minIndex = r;
					}
			    	change_priority(minIndex,worker_queue[minIndex].second,true);
			    }//else{
			    //	swap(worker_queue[minIndex],
			 }
*/
				/*
			if(l < worker_queue.size() && worker_queue[l].second == worker_queue[minIndex].second){
				swap(worker_queue[i],worker_queue[l]);
				minIndex = l;
				//change_priority(l,worker_queue[l].second,true);
			}
			if(r < worker_queue.size() && worker_queue[r].second == worker_queue[minIndex].second){
				swap(worker_queue[minIndex], worker_queue[r]);
				minIndex = r;
				//change_priority(r,worker_queue[r].second,true);
			}
			if(minIndex != i){
				change_priority(minIndex,worker_queue[minIndex].second,true);

			}
			}
			*/
			/*
			else{
					int indexn = i;
					for(int j=indexn+1;j< worker_queue.size();j++){
						if(worker_queue[indexn].second == worker_queue[j].second){
							swap(worker_queue[indexn], worker_queue[j]);
							indexn++;
						}else{
							change_priority(j,worker_queue[j].second,true);
						}
					}
			}
			else if(l < worker_queue.size()){
				if(worker_queue[l].second == worker_queue[i].second){
					//swap(worker_queue[l], worker_queue[i]);
					minIndex = l;
				}
				if( r < worker_queue.size()){
					if(worker_queue[r].second == worker_queue[l].second){
						//swap(worker_queue[r], worker_queue[l]);
						minIndex = r;
					}
				}
				if(minIndex != i){
					swap(worker_queue[i], worker_queue[minIndex]);
					change_priority(minIndex,worker_queue[minIndex].second,true);
				}else{
					int indexn = i;
					for(int j=indexn+1;j< worker_queue.size();j++){
						if(worker_queue[indexn].second == worker_queue[j].second){
							swap(worker_queue[indexn], worker_queue[j]);
							indexn++;
						}else{
							change_priority(j,worker_queue[j].second,true);
						}
					}
				}
			}

*/
			/*
			if(next < worker_queue.size()){
				if(worker_queue[next].second < worker_queue[i].second){
					swap(worker_queue[i], worker_queue[next]);
					change_priority(next,worker_queue[next].second, true);
				}
				else{
					int indexn = i;
					for(int j=indexn+1;j< worker_queue.size();j++){
						if(worker_queue[indexn].second == worker_queue[j].second){
							swap(worker_queue[indexn], worker_queue[j]);
							indexn++;
						}else{
							change_priority(j,worker_queue[j].second,true);
						}
					}
				}
			*/
			//}
			
		}

		/*
		int extractmin(){
			int result = worker_queue[0];
			worker_queue[0] = worker_queue[num_workers_];
			num_workers_-=1;
			siftdown(0);
			return result;
		}
			*/



		void AssignJobs() {
			assigned_workers_.resize(jobs_.size());
			start_times_.resize(jobs_.size());

			vector<long long> workertime(jobs_.size(),0);
			for (int i=0;i<num_workers_;i++){
				if(i<jobs_.size()){
				assigned_workers_[i] =i;
				start_times_[i] = 0;
				worker_queue.push_back(make_pair(i,jobs_[i]));
				//worker_queue.push_back(make_pair(i,0));
				//worker_queue.push_back(make_pair(0,0));
				worker_timer_[i] = 0;
				}
			}

			//for(int i=0;i<worker_queue.size();i++){
				//worker_queue[i].second = jobs_[i];
			//}
			if(worker_queue.size() >= jobs_.size())
				return;

			for(int i=worker_queue.size()/2;i>=0;i--){
			//for(int i=worker_queue.size()-1;i>=0;i--){
				change_priority(i,worker_queue[worker_queue[i].first].second,true);
				//change_priority(i,jobs_[i],true);
				//siftdown(i);
			}
			for(int i=worker_queue.size()/2;i>=0;i--){
				change_priority(i,worker_queue[worker_queue[i].first].second,true);
				//change_priority(i,jobs_[i],true);
			}


			/*
			int firstq = worker_queue[0].first;
			int nextq = 0;
			change_priority(0,jobs_[0],false);
			for(int i=1;i<num_workers_;i++){
				if(worker_queue[0].first == firstq){
					nextq++;
				}
				firstq = worker_queue[nextq].first;
				change_priority(nextq,jobs_[i],false);
				//change_priority(i,jobs_[i],false);
				//worker_queue[i].first = i;
			}
*/



			for(int i=num_workers_;i<jobs_.size();i++){
				std::pair<long long,long long> next= getmin();
				worker_timer_[next.first]=next.second;
				start_times_[i] = worker_timer_[next.first];
				assigned_workers_[i] =next.first;
				change_priority(0,jobs_[i],false);
			}

			//vector<long long> next_free_time(num_workers_, 0);

/*

			   for (int i = 0; i < jobs_.size(); ++i) {
			   int duration = jobs_[i];
			   int next_worker = 0;
			   for (int j = 0; j < num_workers_; ++j) {
			   if (next_free_time[j] < next_free_time[next_worker])
			   next_worker = j;
			   }
			   assigned_workers_[i] = next_worker;
			   start_times_[i] = next_free_time[next_worker];
			   next_free_time[next_worker] += duration;
			   }
			   */
		}

			public:
		void Solve() {
			ReadData();
			AssignJobs();
			WriteResponse();
		}
		};

		int main() {
			std::ios_base::sync_with_stdio(false);
			JobQueue job_queue;
			job_queue.Solve();
			return 0;
		}

