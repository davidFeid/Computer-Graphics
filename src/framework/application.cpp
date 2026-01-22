#include "application.h"
#include "mesh.h"
#include "shader.h"
#include "utils.h" 

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
}

// Render one frame
void Application::Render()
{
	// ...

	int x = framebuffer.width / 2; //Buscamos el centro
	int y = framebuffer.height / 2;
	
	framebuffer.Fill(Color::BLACK);

	//framebuffer.DrawLineDDA(x, y, x + 100 * cos(time), y + 100 * sin(time), Color::WHITE); //Linea DDA	

	//Rectangulo

	framebuffer.DrawRect(100, 100, 200, 150, Color::WHITE, borderWidth, true, Color::BLUE);

	//Triángulo	
	Vector2 p0(400, 100); // Punta arriba
	Vector2 p1(300, 300); // Esquina izquierda abajo
	Vector2 p2(500, 300); // Esquina derecha abajo

	// Llamamos a la nueva función que acabamos de declarar en el .h y el .cpp
	framebuffer.DrawTriangle(p0, p1, p2, Color::RED, fillTriangle, Color::GREEN);

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
		case SDLK_KP_PLUS: // Teclado numérico
			borderWidth++;
			break;

		// Caso para disminuir el grosor
		case SDLK_MINUS:
		case SDLK_KP_MINUS: // Teclado numérico
			borderWidth--;
			// Nunca podrá ser menor a 1
			if (borderWidth < 1) borderWidth = 1;
			break;

		case SDLK_f:
			// El símbolo '!' invierte el valor: si es true pasa a false y viceversa
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