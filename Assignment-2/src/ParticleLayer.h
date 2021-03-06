/*
	Authors:
	Shawn M.          100412327
	Paul Puig         100656910
	Stephen Richards  100458273
*/

#pragma once

#include "GLM.h"

#include "ParticleLayerSettings.h"
#include "Particle.h"

class ParticleEffect;

// Emitter is responsible for emitting (creating, dispatching) particles
class ParticleLayer
{
public:
private:
	unsigned int m_pParticleArraySize;
	unsigned int m_pNumParticles;
	Particle* m_pParticles;
	float     m_pTimeSinceStart;
	float     m_pTimeSinceEmitted;
	ParticleEffect *m_pEffect;

public:
	ParticleLayer(ParticleEffect* parent, ParticleLayerSettings settings);
	ParticleLayer(ParticleEffect* parent);
	~ParticleLayer();

	void initialize();
	void freeMemory();

	void restart() {
		m_pTimeSinceStart = 0;
		m_pTimeSinceEmitted = 0;
	}

	void update(float dt, glm::vec3 origin);
	void draw(glm::vec3 origin);

	void applyForceToParticle(unsigned int idx, glm::vec3 force);

	unsigned int getNumParticles() { return m_pNumParticles; }
	void setNumParticles(unsigned int numParticles) { m_pNumParticles = numParticles > m_pParticleArraySize ? m_pParticleArraySize : numParticles; }

	glm::vec3 getParticlePosition(unsigned int idx);
		
	ParticleLayerSettings Settings;
	
	// ... other properties
	// ... what would be a better way of doing this?
	// Make a keyframe controller for each property! this gives you max control!!
	// See the KeyframeController class
	// (this is what full out particle editors do, ex popcorn fx)
};