#include "application.h"
#include "mesh.h"
#include "shader.h"
#include "utils.h" 
#include "entity.h"

Application::Application(const char* caption, int width, int height)
{
	this->window = createWindow(caption, width, height);

	int w,h;
	SDL_GetWindowSize(window,&w,&h);

	this->mouse_state = 0;
	this->time = 0.f;
	this->window_width = w;
	this->window_height = h;
	this->keystate = SDL_GetKeyboardState(nullptr);

	this->framebuffer.Resize(w, h);
}

Application::~Application()
{
}

void Application::Init(void)
{
	std::cout << "Initiating app..." << std::endl;

	// 1. Cargamos un mesh de los archivos del framework
    Mesh* mesh = Mesh::Get("data/head.obj"); 
    
    // 2. Creamos la matriz de modelo (posición en el mundo)
    Matrix44 model_matrix;
    model_matrix.SetIdentity(); // Empezamos en el origen (0,0,0) [cite: 316, 317]

    // 3. Instanciamos la entidad [cite: 53]
    my_entity = new Entity(mesh, model_matrix);
}

// Render one frame
void Application::Render()
{
	// ...

	int x = framebuffer.width / 2; //Buscamos el centro
	int y = framebuffer.height / 2;
	
	framebuffer.Fill(Color::BLACK);

    // Configuramos la cámara con matrices de ejemplo para que se vea algo [cite: 72, 73]
    Camera camera;
    camera.SetExampleViewMatrix();
    camera.SetExampleProjectionMatrix();

    // Dibujamos nuestra entidad [cite: 76, 78]
    if (my_entity != nullptr) {
        my_entity->Render(&framebuffer, &camera, Color::WHITE);
    }

    framebuffer.Render();
}

// Called after render
void Application::Update(float seconds_elapsed)
{

}

//keyboard press event 
void Application::OnKeyPressed( SDL_KeyboardEvent event )
{
	// KEY CODES: https://wiki.libsdl.org/SDL2/SDL_Keycode
	switch(event.keysym.sym) {
		case SDLK_ESCAPE: exit(0); break; // ESC key, kill the app
		
		// Caso para aumentar el grosor
		case SDLK_PLUS:
		case SDLK_KP_PLUS: // Teclado num�rico
			borderWidth++;
			break;

		// Caso para disminuir el grosor
		case SDLK_MINUS:
		case SDLK_KP_MINUS: // Teclado num�rico
			borderWidth--;
			// Nunca podr� ser menor a 1
			if (borderWidth < 1) borderWidth = 1;
			break;

		case SDLK_f:
			// El s�mbolo '!' invierte el valor: si es true pasa a false y viceversa
			fillTriangle = !fillTriangle;
			break;
	}
}

void Application::OnMouseButtonDown( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_LEFT) {

	}
}

void Application::OnMouseButtonUp( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_LEFT) {

	}
}

void Application::OnMouseMove(SDL_MouseButtonEvent event)
{
	
}

void Application::OnWheel(SDL_MouseWheelEvent event)
{
	float dy = event.preciseY;

	// ...
}

void Application::OnFileChanged(const char* filename)
{ 
	Shader::ReloadSingleShader(filename);
}