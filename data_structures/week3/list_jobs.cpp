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


		void assignfirst(){

			vector<long long> workertime(jobs_.size(),0);
			for (int i=0;i<num_workers_;i++){
				assigned_workers_[i] =i;
				start_times_[i] = 0;
				worker_queue.push_back(make_pair(i,0));
				worker_timer_[i] = 0;
			}

			for(int i=0;i<num_workers_;i++){
				change_priority(0,jobs_[i],false);
				//siftdown(0);
			}



			for(int i=num_workers_;i<jobs_.size();i++){
				std::pair<long long,long long> next= getmin();
				worker_timer_[next.first]=next.second;
				start_times_[i] = worker_timer_[next.first];
				assigned_workers_[i] =next.first;
				change_priority(0,jobs_[i],false);
			}
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
				siftdown(i);
		}

		void siftdown(int i ){
			int next = i+1;
			if(next < worker_queue.size()){
				if(worker_queue[next].second < worker_queue[i].second){
					swap(worker_queue[i], worker_queue[next]);
					change_priority(next,worker_queue[next].second, true);
				}
				else {
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
			// TODO: replace this code with a faster algorithm.
			assigned_workers_.resize(jobs_.size());
			start_times_.resize(jobs_.size());
			assignfirst();

			vector<long long> next_free_time(num_workers_, 0);

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

