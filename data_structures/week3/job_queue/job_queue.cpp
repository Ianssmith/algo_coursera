#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::make_pair;

class JobQueue {
 private:
  long long num_workers_;
  vector<long long> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  vector<long long> worker_timer_;
  vector<std::pair<long long,long long>> worker_queue;
  int previous = 0;


  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    long long m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
	worker_timer_.resize(num_workers_);
	previous = num_workers_-1;
  }

  int parent(int i){
	  int a;
	  (i%2 == 0)? a=(i/2)-1 : a=i/2;
	  return a;
  }

  int lc(int i){
	  return (i*2)+1;
  }

  int rc(int i){
	  return (i*2)+2;
  }

  void heapify(int i){
	  int l = lc(i);
	  int r = rc(i);
	  int minIndex = i;
	  if(l<worker_queue.size() && worker_queue[l].second < worker_queue[minIndex].second)
		  minIndex = l;
	  if(r<worker_queue.size() && worker_queue[r].second < worker_queue[minIndex].second)
		  minIndex = r;
	  if(minIndex != i){
		  swap(worker_queue[i],worker_queue[minIndex]);
		  heapify(minIndex);
	  }
  }

  void makeheap(){
	  for(int k=worker_queue.size()/2;k>=0;k--){
	  //for(int k=worker_queue.size();k>=0;k--){
		  heapify(k);
	  }
  }

  void insert_el(int assignment_num, long long val){
	  //worker_queue.push_back(make_pair(threadnum,val));
	  int i = worker_queue.size()-1;
	  bool assigned = false;
	  //int i = 0;

	  while(!assigned && i>=0){
		if(worker_queue[worker_queue.size()-1].second == LLONG_MAX){
			worker_queue[worker_queue.size()-1].second = val;
			//assigned_workers_[assignment_num] = worker_queue[worker_queue.size()-1].first;
			assigned = true;
		}else{
			i--;
			swap(worker_queue[i],worker_queue[worker_queue.size()-1]);
		}
	  }
	  if(assigned == false){
		cout<<"could not assign element. "<<val<<'\n';
	  }else{
	  //makeheap();
	  /*
	  while(i>0 && worker_queue[parent(i)].second > worker_queue[i].second){
		  swap(worker_queue[i],worker_queue[parent(i)]);
		  i = parent(i);
	  }
	  */
		siftup();
	  }
  }

  void siftup(){
	  int i=worker_queue.size()-1;
	  int ran = 0;
	  //??? ran < or <=
	  while(i>0 && worker_queue[parent(i)].second >= worker_queue[i].second && ran<worker_queue.size()){
			  if(worker_queue[parent(i)].second == worker_queue[i].second){
				  if(worker_queue[parent(i)].first > worker_queue[i].first){
					swap(worker_queue[i],worker_queue[parent(i)]);
					i = parent(i);
				  }
			  }else{
				swap(worker_queue[i],worker_queue[parent(i)]);
				i = parent(i);
			  }
		  ran++;
	  }
  }

  std::pair<long long,long long> getmin(){
	  return worker_queue[0];
  }
  

  void AssignJobs() {
	assigned_workers_.resize(jobs_.size());
	start_times_.resize(jobs_.size());

	vector<long long> workertime(jobs_.size(),0);
			for (int i=0;i<num_workers_;i++){
				if(i<jobs_.size()){
					assigned_workers_[i] =i;
					start_times_[i] = 0;
					worker_queue.push_back(make_pair(i,jobs_[i]));
					//worker_queue.push_back(make_pair(i,LLONG_MAX));
					//insert_el(i,jobs_[i]);
					worker_timer_[i] = 0;
					previous = -1;
				}
			}
			//for(int i=num_workers_;i<worker_queue.size()*2;i++){
			/*
			for(int i=0;i<worker_queue.size();i++){
				insert_el(0,jobs_[i]);
			}
			*/
			//makeheap();
			/*
			int k=0;
			for(int i=num_workers_;i<num_workers_*2;i++){
				assigned_workers_[i] = worker_queue[k].first;
				start_times_[i] = worker_queue[k].second;
				k++;
			}
			*/

			if(worker_queue.size() >= jobs_.size())
				return;

			makeheap();

			//for(int i=num_workers_*2;i<jobs_.size();i++){
			for(int i=num_workers_;i<jobs_.size();i++){
				std::pair<long long,long long> next= getmin();
				int ll = next.first;
				worker_timer_[next.first]=next.second;
				start_times_[i] = worker_timer_[next.first];
				assigned_workers_[i] =next.first;
				worker_queue[0].second+=jobs_[i];
				previous = next.first;
				for(int k=0;k<worker_queue.size()-1;k++){
					swap(worker_queue[k],worker_queue[k+1]);
				}
				siftup();
			}
	
    // TODO: replace this code with a faster algorithm.
	/*
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
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

