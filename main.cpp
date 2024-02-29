#include <windows.h>
#include <iostream>

    double gamma_;
    double omega_;
    std::pair<int, int>alpha_;


    int main(int argc, char* argv[]) {
        omega_ = 0.25;
       
       



        return 0;
    }
   
    //int degree_;
    //double sigma_;

    //double gamma_;
    //double omega_;
    //std::pair<int, int> alpha_;
//
//    LinearModel* model1;
//    LinearModel* model2;
//    Protocol * protocol;
//    Connection* connection;
//public:
//
//
//    MyManager() :
//            Manager()
//    {
//        //degree_ = 0;
//        //sigma_ = 0.0;
//        //timecounter_ = new TimeCounter;
//        //timecounter_->setStepInterval(0.0, 5.0, 0.1);
//    }
//    ~MyManager()
//    {
//        delete model1;
//        delete model2;
//        delete protocol;
//        delete connection;
//    }
//    void setComputeParameters(std::pair<int, int> _alpha, double _gamma, double _lambda)
//    {
//        alpha_ = _alpha;
//        gamma_ = _gamma;
//        omega_ = _lambda;
//    }
//    /*
//    void setComputeParameters(int _degree, double _sigma)
//    {
//        degree_ = _degree;
//        sigma_ = _sigma;
//    }
//    void setNonadditiveModel()
//    {
//        //! (4) Создаем модель и выбораем численную схему:
//        Connection* connection = new TriadicConnection(sigma_, degree_);
//        //Connection* connection = new FullyTriadicConnection(_degree);
//        NonadditiveProtocol * protocol = new NonadditiveProtocol(connection);
//        LinearModel* model1 = new LinearModel(timecounter, protocol, "state");
//        model1->setCollective(collective);
//        network->setMASModel(model1, new EulerScheme(model1));
//        //! (6) Параметры для сохранения данных:
//        network->setDumpParameter("solve");
//        network->setDumpParameter("weight");
//        //network->setDumpParameter("desync");
//        //network->setDumpParameter("order");
//        std::cout << "(4) DifferentialEquation is assigned: success" << std::endl;
//
//        delete model1;
//        delete protocol;
//    }
//    */
//    void setDipoleModel()
//    {
//        //double epsilon_ = 2.0;
//        //double Psi_ = ph::pi() * 30.0 / 180.0;
//        //! (4) Создаем модель и выбораем численную схему:
//        connection = new PairConnection();
//        //protocol = new AnisotropicDipoleProtocol(connection, alpha_, gamma_, omega_);
//        //protocol = new AnisotropicDipoleProtocol(connection, std::pair(1,1), epsilon_,Psi_, omega_);
//        protocol = new FixedDipoleProtocol(connection, alpha_, gamma_, omega_); //-1.0 / 7.0 * (5.0 - 3.0 * sqrt(2.0))
//        model1 = new LinearModel(timecounter, protocol, "state");
//        model1->setCollective(collective);
//        model2 = new LinearModel(timecounter, protocol, "phase");
//        model2->setCollective(collective);
//        network->setMASModel(model1, new EulerScheme(model1));
//        network->setMASModel(model2, new EulerScheme(model2));
//        std::cout << "(4) DifferentialEquation is assigned: success" << std::endl;
//
//        //! (5) Параметры для сохранения данных:
//        network->setDumpParameter("solve");
//        //network->setDumpParameter("weight");
//        //network->setDumpParameter("desync");
//        //network->setDumpParameter("order");
//
//        //SimplePairProtocol* protocol = new SimplePairProtocol();
//    }
//
//};
//
//
//__int64 GetFolderCountFiles( const char* szPath){
//    if( !szPath || !*szPath) return 0;
//    __int64      i64CountFiles = 0;
//    char Path[ _MAX_PATH];
//    WIN32_FIND_DATA      data;
//    strcpy( Path, szPath);
//    if( Path[ strlen( Path) - 1] != '\\') strcat( Path, "\\");
//    strcat( Path,"*.*");
//    HANDLE hFind = FindFirstFile( Path, &data);
//    if( hFind != INVALID_HANDLE_VALUE){
//        while(1){
//            if( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
//                if( strcmp(data.cFileName, ".") && strcmp(data.cFileName, "..") ){
//                    char NewPath[ _MAX_PATH];
//                    strcpy( NewPath, szPath);
//                    strcat( NewPath, "\\");
//                    strcat( NewPath, data.cFileName);
//                    i64CountFiles += GetFolderCountFiles( NewPath);
//                }
//            }
//            else i64CountFiles++;
//            BOOL bCode = FindNextFile( hFind, &data);
//            if (!bCode && GetLastError() == ERROR_NO_MORE_FILES) break;
//        }
//        FindClose( hFind);
//    }
//    return i64CountFiles;
//}
//
//int dircr(const std::string& dirname){
//
//    DWORD ftyp = GetFileAttributesA(dirname.c_str());
//    char* my_dirname = strcpy(new char[dirname.length() + 1], dirname.c_str());
//    if (ftyp == INVALID_FILE_ATTRIBUTES) CreateDirectory (my_dirname, NULL);
//    if (ftyp & FILE_ATTRIBUTE_DIRECTORY) return GetFolderCountFiles(my_dirname);
//}
//
//
//
//
//
//int main(int argc, char *argv[])
//{
//    double omega = -0.25;
//    double gamma = ph::pi() * 60.0 / 180.0;
//    std::pair<int, int> alpha = std::pair(1, 0);
//    Vector2d beta = Vector2d(cos(gamma), sin(gamma));
//
//    //double omega = -0.25;
//    int dir_file_count;
//    std::string dirname;
//    auto index = 1;
//    auto* timecounter = new TimeCounter;
//    timecounter->setStepInterval(0.0, 1000.0, 0.1);
//    MyManager* manager = new MyManager;
//
//    manager->setComputeParameters(alpha, gamma, omega);
//    manager->setTimeCounter(timecounter);
//    manager->setSpaceParametrs(2, "E");
//    manager->setAgentParameters(5, "d-agent");
//    manager->setGraphParameters("C");
//
//
//    double r0 = 5.0;
//    double x0 = 100.0;
//    double theta_s = ph::pi() / 3.0;
//    double deltaTheta;
//    std::vector<std::pair<VectorXd, double>> initialConditions;
//    for (int i = 0; i < 5; i++)
//    {
//        deltaTheta = 2.0 * ph::pi() / 5.0 * i;
//        initialConditions.emplace_back(std::pair(Vector2d(x0 + r0 * cos(ph::pi() / 2.0 + deltaTheta), x0 +  r0 * sin(ph::pi() / 2.0 + deltaTheta)), theta_s + deltaTheta));
//    }
//    //manager->setInitialConditions(initialConditions);
//
//
//    manager->create();
//    manager->setDipoleModel();
//
//    if (index == 1) {
//        dirname = "beta_1 = " + std::to_string(beta(0)).substr(0, std::to_string(beta(0)).size()-4) + ", beta_2 = " + std::to_string(beta(1)).substr(0, std::to_string(beta(1)).size()-4);
//
//        dir_file_count = dircr("C:\\Cpp-Projects\\OpenSynch\\cmake-build-debug\\output\\om = -0.25\\" + dirname);
//        manager->setDumpParameters("output/om = -0.25/" + dirname + "/", std::to_string(dir_file_count + 1));
//        //manager->setComputeParameters(-2, 5.0);
//        manager->computer();
//
//        std::cout << "Calculation: success" << std::endl;
//    } else if (index == 2) {}
//
//
//    delete manager;
//    delete timecounter;
//    std::cout << "Delete: success" << std::endl;
//
//    return EXIT_SUCCESS;



