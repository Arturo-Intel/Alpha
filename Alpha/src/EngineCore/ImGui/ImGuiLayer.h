#pragma once

#include "EngineCore/Layer.h"

#include "EngineCore/Events/MouseEvent.h"
#include "EngineCore/Events/ApplicationEvent.h"
#include "EngineCore/Events/KeyEvent.h"

namespace Alpha {
	class ALPHA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override; 
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
		
	private:
		float m_Time = 0;
	};
}

