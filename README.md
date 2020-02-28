# kari
The best implementation of MVC Design Pattern when you build your Mobile Application based on Google Flutter Framework

## Create

- ## Initialize kari in your flutter project
  - kari init
- ## Generate a controller
  - kari generate controller ControllerName  <br/>
  eg: **kari generate controller auth/Authentication**:
  it will generate AuthenticationController.dart under [projectDir/lib/app/controllers/auth]()
  ```
  @controller
  class AuthenticationController{

     void loginScreen(BuildContext context){
         view("login", context, RouteMode.PUSH);
     }
  }

  ```
  
- ## Generate a Screen
  - kari generate screen ScreenClassName ScreenName  <br/>
  eg: **kari generate screen auth/LoginForm login**:
  it will generate LoginForm-screen.dart under [projectDir/lib/app/screens/auth](). Actually, **Kari** will suppose that you
  want to generate your screen as [StatefulWidget](https://api.flutter.dev/flutter/widgets/StatefulWidget-class.html)
  
  ```
  @Screen("login")
  class LoginFormScreen extends StatefulWidget{
     @override
     _LoginFormScreenState createState() => _LoginFormScreenState();
  }

  class _LoginFormScreenState extends State<LoginFormScreen> {

     @override
     Widget build(BuildContext context) {
         return Scaffold(
             body: Center(
                 child: Text("LoginFormScreen Works!!! :)")
             )
         );
     }

  }
  ```
- ## Add a Route
  Open [app/routes/Routes.dart]() and subscribe your route as <br />
  ```
  void registeredRoute() {
    Route.data("/login",  "AuthenticationController@loginScreen");
  }
  ```
  To load this route this code
  
  ```
  FlatButton(
    child: Text("Log in"),
    onPressed: () => Router.goto("/login", parameter: context),
  )
    
  ```

## Build & Run
- ## Build your project
  - kari build [flutter additionals build parameters]  <br/>
  eg: **kari build apk** [for more informations about flutter build & release](https://flutter.dev/docs/deployment/android):
- ## Run your project
  - kari run <br/> [for more informations about flutter test drive](https://flutter.dev/docs/get-started/test-drive):
  
