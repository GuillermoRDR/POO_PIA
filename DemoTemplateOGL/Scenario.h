#ifndef GRAPHICSRR_H
#define GRAPHICSRR_H

#ifdef _WIN32 
#include <windows.h>
#include <windowsx.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include "Base/camera.h"
#include "Base/Billboard.h"
#include <iostream>
#include "Base/Scene.h"
#include "Texto.h"
#include "Billboard2D.h"
#include <random>
#include <chrono>

class Scenario : public Scene {
private:
	SkyDome* sky;
	Terreno* terreno;
	std::vector<Billboard*> billBoard;
	std::vector<Billboard2D*> billBoard2D;
	std::vector<Model*> ourModel;
	std::vector<Zombie*> ourZombies;
	Model* camara;
	Water* water;
	float angulo;
	int animacion = 0;
	int frameArbol = 1;
	std::vector<Texto*> ourText;
	std::chrono::high_resolution_clock::time_point startTime;
	bool showBillboard; // Indica si los billboards están activos
public:
	Scenario(Camera* cam) : startTime(std::chrono::high_resolution_clock::now()), showBillboard(true) {
		glm::vec3 translate;
		glm::vec3 scale;
		Model* model = new Model("models/Cube.obj", cam);
		translate = glm::vec3(0.0f, 0.0f, 3.0f);
		scale = glm::vec3(0.25f, 0.25f, 0.25f);	// it's a bit too big for our scene, so scale it down
		model->setScale(&scale);
		model->setTranslate(&translate);
		InitGraph(model);
	}
	Scenario(Model* camIni) : startTime(std::chrono::high_resolution_clock::now()), showBillboard(true) {
		InitGraph(camIni);
	}
	void InitGraph(Model* main) {
		float matAmbient[] = { 1,1,1,1 };
		float matDiff[] = { 1,1,1,1 };
		angulo = 0;
		camara = main;
		//creamos el objeto skydome
		sky = new SkyDome(32, 32, 30, (WCHAR*)L"skydome/cielo.png", main->cameraDetails);
		//creamos el terreno
		terreno = new Terreno((WCHAR*)L"textures/nuevoTerreno.png", (WCHAR*)L"textures/arena.jpg", 500, 500, main->cameraDetails);
		water = new Water((WCHAR*)L"textures/terreno.bmp", (WCHAR*)L"textures/wata.png", 200, 150, camara->cameraDetails);
		glm::vec3 translate;
		glm::vec3 scale;
		glm::vec3 rotation;
		translate = glm::vec3(-180.0f, 2.0f, -120.0f);
		rotation = glm::vec3(1.0f, 0.0f, 0.0f); //rotation X
		water->setRotX(180); // 45° rotation
		water->setTranslate(&translate);
		ourModel.emplace_back(main);
		// load models
		// ----------------------------------------------------------------------------------------------- Guillermo René Dávila Roque // Matrícula: 2003063 ----------------------------------------------------------------------------------------------- 
		Model* model;
		Zombie* zombie;

		model = new Model("models/bat/base.obj", main->cameraDetails);// -------------------------------------------- Organico ---------------------------------------------------- 
		translate = glm::vec3(5.0f, terreno->Superficie(0.0f, 60.0f), 5.0f);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		model->setTieneColision(false);
		ourModel.emplace_back(model);

		model = new Model("models/camioneta/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/vocho/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/van/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/botes_basura/botes_basura.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		// ----------------------------------------------------------------------------------------------- Construccion -----------------------------------------------------------------------------------------------

		model = new Model("models/construccion/vallasFrente/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/carretera/carretera.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		model->setTieneColision(false);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/entradaDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/entradaIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/entradaSup/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasDetDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasDetIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasEntDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasEntIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasIzqFrente/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasIzqIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/maderasRest/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesDetrasDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesDetrasIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesIzqFrente/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesIzqIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/paredesSegPiso/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/parkin/parkin.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setTieneColision(false);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/puertaOx/puerta_ox.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/soportePuertaOx/soporte_puerta_ox.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/sueloPB/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setTieneColision(false);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/sueloPiedra/suelo_piedra.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setTieneColision(false);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/techos/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/tejas/tejas.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/vallasDetras/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/vallasLateralDer/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/vallasLateralIzq/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 0), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);


		model = new Model("models/construccion/mesasCentro/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/mesasDerDet/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/mesasDerFre/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/mesasDetrasDet/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/mesasDetrasFrente/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/mesasIzqDet/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		model = new Model("models/construccion/mesasIzqFre/base.obj", main->cameraDetails);
		translate = glm::vec3(0, terreno->Superficie(0, 60.0f), 0);
		model->setTranslate(&translate);
		scale = glm::vec3(9.0f, 9.0f, 9.0f);
		model->setScale(&scale);
		ourModel.emplace_back(model);

		// ----------------------------------------------------------------------------------------------- Fin de Construccion -----------------------------------------------------------------------------------------------

		//model = new Model("models/zombieM/base.fbx", main->cameraDetails);
		//translate = glm::vec3(0.0f, terreno->Superficie(0.0f, 0.0f) +5 , 10.0f);
		//scale = glm::vec3(1.1f, 1.1f, 1.1f);	// it's a bit too big for our scene, so scale it down
		//model->setTranslate(&translate);
		//model->setScale(&scale);/*
		//model->setRotY(180);*/
		//ourModel.emplace_back(model);
		//try{
		//	Animation *ani = new Animation("models/zombieM/base.fbx", model->GetBoneInfoMap(), model->GetBoneCount());
		//    model->setAnimator(new Animator(ani));
		//}catch(...){
		//	cout << "Could not load animation!\n";
		//}

		//model = new Model("models/Silly_Dancing.dae", main->cameraDetails);
		//translate = glm::vec3(10.0f, terreno->Superficie(0.0f, 60.0f) , 60.0f);
		//scale = glm::vec3(0.1f, 0.1f, 0.1f);	// it's a bit too big for our scene, so scale it down
		//model->setTranslate(&translate);
		//model->setScale(&scale);
		//model->setRotY(180);
		//ourModel.emplace_back(model);
		//try{
		//	Animation *ani = new Animation("models/Silly_Dancing.dae", model->GetBoneInfoMap(), model->GetBoneCount());
		//    model->setAnimator(new Animator(ani));
		//}catch(...){
		//	cout << "Could not load animation!\n";
		//}
		for (int i = 0; i < 8; i++) {
			float posRandX = posXRandLluvia();
			float posRandZ = posZRandLluvia();
			glm::vec3 coords = glm::vec3(posRandX, terreno->Superficie(posRandX, posRandZ), posRandZ);
			zombie = new Zombie("models/zombieH/base.obj", main->cameraDetails, coords);
			scale = glm::vec3(10.0f, 10.0f, 10.0f);
			zombie->setScale(&scale);
			ourZombies.emplace_back(zombie);
		}

		for (int i = 0; i < 8; i++) {
			float posRandX = posXRandLluvia();
			float posRandZ = posZRandLluvia();
			glm::vec3 coords = glm::vec3(posRandX, terreno->Superficie(posRandX, posRandZ), posRandZ);
			zombie = new Zombie("models/zombieM/base.obj", main->cameraDetails, coords);
			scale = glm::vec3(10.0f, 10.0f, 10.0f);
			zombie->setScale(&scale);
			ourZombies.emplace_back(zombie);
		}

		for (int i = 0; i < 4; i++) {
			float posRandX = posXRandLluvia();
			float posRandZ = posZRandLluvia();
			glm::vec3 coords = glm::vec3(posRandX, terreno->Superficie(posRandX, posRandZ), posRandZ);
			zombie = new Zombie("models/rata/base.obj", main->cameraDetails, coords);
			scale = glm::vec3(10.0f, 10.0f, 10.0f);
			zombie->setScale(&scale);
			ourZombies.emplace_back(zombie);
		}

		//Menús con billboards
		inicializaBillboards();
		ourText.emplace_back(new Texto(L"Esta es una prueba", 20, 0, 0, SCR_HEIGHT, 0, camara));
		billBoard2D.emplace_back(new Billboard2D((WCHAR*)L"billboards/titulo.png", 1, 1, 0, 0, 0, camara->cameraDetails));
		scale = glm::vec3(800.0f, 600.0f, 0.0f);	// it's a bit too big for our scene, so scale it down
		billBoard2D.back()->setScale(&scale);
		std::wstring wCoordenadas = L"X: " + std::to_wstring(getMainModel()->getTranslate()->x) + L" Y: " + std::to_wstring(getMainModel()->getTranslate()->y) + L" Z: " + std::to_wstring(getMainModel()->getTranslate()->z);
		ourText.emplace_back(new Texto(wCoordenadas, 15, 0, 0, 0, 0, camara));


	}

	void inicializaBillboards() {
		for (int billsA = 0; billsA < 8; billsA++) {
			float posXRand = posXRandf();
			float posZRand = posZRandf();
			float posYRand = terreno->Superficie(posXRand, posZRand);
			billBoard.emplace_back(new Billboard((WCHAR*)L"billboards/arbolSeco.png", 8, 10, posXRand, posYRand - 1, posZRand, camara->cameraDetails));
		}
		for (int billsA = 0; billsA < 8; billsA++) {
			float posXRand = posXRandf();
			float posZRand = posZRandf();
			float posYRand = terreno->Superficie(posXRand, posZRand);
			billBoard.emplace_back(new Billboard((WCHAR*)L"billboards/arbustoSeco.png", 3, 3, posXRand, posYRand - 1, posZRand, camara->cameraDetails));
		}
		for (int billsA = 0; billsA < 8; billsA++) {
			float posXRand = posXRandf();
			float posZRand = posZRandf();
			float posYRand = terreno->Superficie(posXRand, posZRand);
			billBoard.emplace_back(new Billboard((WCHAR*)L"billboards/cactus.png", 6, 8, posXRand, posYRand - 1, posZRand, camara->cameraDetails));
		}
		for (int billsLluvia = 0; billsLluvia < 400; billsLluvia++) {
			random_device rd;
			mt19937 gen(rd());
			uniform_real_distribution<float> distribucion(0.4f, 2.8f);
			float posXRand = posXRandLluvia();
			float posZRand = posZRandLluvia();
			float posYRand = posYRandLluvia();
			billBoard.emplace_back(new Billboard((WCHAR*)L"billboards/gota.png", 0.1f, distribucion(gen), posXRand, posYRand - 1, posZRand, camara->cameraDetails));
		}
	}

	//Métodos que retornan numeros random dentro de un area predefinida x = -254 a 254  y z = 5 a 250
	float posXRandf() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<float> distribucion(-254.0f, 254.0f);
		return distribucion(gen);
	}
	float posZRandf() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<float> distribucion(30.0f, 250.0f);
		return distribucion(gen);
	}
	float posXRandLluvia() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<float> distribucion(-250.0f, 250.0f);
		return distribucion(gen);
	}
	float posZRandLluvia() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<float> distribucion(-250.0f, 250.0f);
		return distribucion(gen);
	}
	float posYRandLluvia() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<float> distribucion(0.0f, 100.0f);
		return distribucion(gen);
	}

	//el metodo render toma el dispositivo sobre el cual va a dibujar
	//y hace su tarea ya conocida
	Scene* Render() {
		//borramos el biffer de color y el z para el control de profundidad a la 
		//hora del render a nivel pixel.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		//		glClearColor(255.0f, 255.0f, 255.0f, 255.0f);

				// Actualizamos la camara
		camara->cameraDetails->CamaraUpdate(camara->getRotY(), camara->getTranslate());

		std::wstring wCoordenadas = L"X: " + std::to_wstring(getMainModel()->getTranslate()->x) + L" Y: " + std::to_wstring(getMainModel()->getTranslate()->y) + L" Z: " + std::to_wstring(getMainModel()->getTranslate()->z);
		ourText[1]->setTexto(wCoordenadas);

		//Animacion de la lluvia
		for (int i = 24; i < billBoard.size(); i++) {
			glm::vec3 translate;
			if (billBoard[i]->getTranslate()->y <= 100.0f && billBoard[i]->getTranslate()->y >= 0.0f) {
				translate = glm::vec3(billBoard[i]->getTranslate()->x, billBoard[i]->getTranslate()->y -= 6.0f, billBoard[i]->getTranslate()->z);
				billBoard[i]->setTranslate(&translate);
				if (billBoard[i]->getTranslate()->x >= -250.0f && billBoard[i]->getTranslate()->x <= 250.0f) {
					translate = glm::vec3(billBoard[i]->getTranslate()->x += 0.3f, billBoard[i]->getTranslate()->y, billBoard[i]->getTranslate()->z);
					billBoard[i]->setTranslate(&translate);
				}
				else {
					translate = glm::vec3(-250.0f, billBoard[i]->getTranslate()->y, billBoard[i]->getTranslate()->z);
					billBoard[i]->setTranslate(&translate);
				}
			}
			else {
				translate = glm::vec3(billBoard[i]->getTranslate()->x, 100.0f, billBoard[i]->getTranslate()->z);
				billBoard[i]->setTranslate(&translate);
			}
		}

		// Definimos una variable para la dirección del movimiento (-1: izquierda, 1: derecha)
		static int direction = 1;
		// Obtenemos la posición actual del modelo
		float currentX = ourModel[28]->getTranslate()->x;
		// Verificamos si estamos en los límites del rango
		if (currentX >= 15.0f) {
			// Si estamos en el límite derecho, invertimos la dirección
			direction = -1;
		}
		else if (currentX <= -15.0f) {
			// Si estamos en el límite izquierdo, invertimos la dirección
			direction = 1;
		}

		// Movemos el objeto en la dirección actual
		currentX += direction * 0.1f; // 0.1f es la velocidad del movimiento
		glm::vec3 translate = glm::vec3(currentX, ourModel[28]->getTranslate()->y, ourModel[28]->getTranslate()->z);
		ourModel[28]->setTranslate(&translate);
		
		// Decimos que dibuje la media esfera
		sky->Draw();
		// Ahora el terreno
		terreno->Draw();
		water->Draw();
		// Dibujamos cada billboard que este cargado en el arreglo de billboards.
		for (int i = 0; i < billBoard.size(); i++)
			billBoard[i]->Draw();

		auto currentTime = std::chrono::high_resolution_clock::now();
		float elapsedTime = std::chrono::duration<float>(currentTime - startTime).count();

		// Desactiva los billboards después de 10 segundos
		if (elapsedTime > 65.0f) {
			showBillboard = false;
		}

		// Dibuja solo si están activos
		if (showBillboard) {
			for (int i = 0; i < billBoard2D.size(); i++) {
				billBoard2D[i]->Draw();
			}
		}
		/*Dibujamos cada modelo que este cargado en nuestro arreglo de modelos*/
		for (int i = 0; i < ourModel.size(); i++) {
			ourModel[i]->Draw();
		}

		// Dibujamos cada zombie que este cargado en nuestro arreglo de zombies
		for (int i = 0; i < ourZombies.size(); i++) {
			ourZombies[i]->Actualizar(ourZombies[i], camara);
			ourZombies[i]->Draw();
		}

		for (int i = 0; i < ourText.size(); i++) {
			ourText[i]->Draw();
		}
		// Le decimos a winapi que haga el update en la ventana
		return this;
	}

	std::vector<Model*>* getLoadedModels() {
		return &ourModel;
	}
	std::vector<Billboard*>* getLoadedBillboards() {
		return &billBoard;
	}
	Model* getMainModel() {
		return this->camara;
	}
	float getAngulo() {
		return this->angulo;
	}
	void setAngulo(float angulo) {
		this->angulo = angulo;
	}
	SkyDome* getSky() {
		return sky;
	}
	Terreno* getTerreno() {
		return terreno;
	}

	~Scenario() {
		if (this->sky != NULL) {
			delete this->sky;
			this->sky = NULL;
		}
		if (this->terreno != NULL) {
			delete this->terreno;
			this->terreno = NULL;
		}
		if (billBoard.size() > 0)
			for (int i = 0; i < billBoard.size(); i++)
				delete billBoard[i];
		if (billBoard2D.size() > 0)
			for (int i = 0; i < billBoard2D.size(); i++)
				delete billBoard2D[i];
		this->billBoard.clear();
		if (ourText.size() > 0)
			for (int i = 0; i < ourText.size(); i++)
				delete ourText[i];
		this->ourText.clear();
		if (ourModel.size() > 0)
			for (int i = 0; i < ourModel.size(); i++)
				if (ourModel[i] != camara)
					delete ourModel[i];
		this->ourModel.clear();
		if (ourZombies.size() > 0)
			for (int i = 0; i < ourZombies.size(); i++)
				if (ourZombies[i] != camara)
					delete ourZombies[i];
		this->ourZombies.clear();
	}
	}; 

#endif
