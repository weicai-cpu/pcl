
#include<pcl/visualization/cloud_viewer.h>
#include<iostream>
#include<pcl/io/io.h>
#include<pcl/io/pcd_io.h>
#include<pcl/io/ply_io.h>
#include<pcl/point_types.h>

int user_data;
using std::cout;
using namespace std;


void viewerOneOff(pcl::visualization::PCLVisualizer& viewer) {
	viewer.setBackgroundColor(1.0, 0.5, 1.0);
}

int main (int argc, const char* argv[])
{
    cout << "start pclTest \n";
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	const char* strfilepath= argv[1];
	cout << strfilepath << "\n";
	if (-1 == pcl::io::loadPCDFile(strfilepath, *cloud)) {
		cout << "error input!" << endl;
		return -1;
	}

	cout << cloud->points.size() << endl;
	pcl::visualization::CloudViewer viewer("Cloud Viewer");

	viewer.showCloud(cloud);
	viewer.runOnVisualizationThreadOnce(viewerOneOff);
	system("pause");
	return 0;
}