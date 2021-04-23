import { useRouter } from "next/router";
import { createContext, useContext, useEffect, useState } from "react";
import makeWs from "../hooks/makeWs";
import { GoEvent } from "../types/GameActions";
import { useQuestion } from "./QuestionContext";

const choices = ["benq", "tourist", "dkasabov", "nwatx"];

export enum GameStage {
	READYUP,
	PLAY,
	END,
}

type GameContextType = {
	stage: GameStage;
	gameRoom: string;
	[key: string]: any;
};

const GameContext = createContext<GameContextType>({
	stage: GameStage.READYUP,
	gameRoom: "",
});

export const GameProvider = ({ children }) => {
	const [stage, setState] = useState<GameStage>(GameStage.READYUP);
	const router = useRouter();
	const { gameRoom } = router.query;
	const { updateQuestion } = useQuestion();

	const handleMessage = ({ data }: MessageEvent) => {
		console.log(data);
		const parsedData = JSON.parse(data) as GoEvent;
		console.log(parsedData.action);
		switch (parsedData.action) {
			case "next-question":
				updateQuestion(parsedData);
				break;
			case "end-game":
				nextStage();
				break;
		}
	};
	
	const { ws, sendWs } = makeWs(gameRoom as string, {
		onmessage: (e: MessageEvent) => {
			console.log("onmessage", e);
			handleMessage(e);
		},
		onopen: () => console.log(`Connected to ${gameRoom}`),
	});

	const newGame = () => {
		setState(GameStage.READYUP);
	};

	const nextStage = () => {
		if (stage !== GameStage.END) setState(stage + 1);
	};

	return (
		<GameContext.Provider
			value={{
				stage,
				nextStage,
				newGame,
				sendWs,
				gameRoom: gameRoom as string,
			}}
		>
			{children}
		</GameContext.Provider>
	);
};

export const useGame = () => useContext(GameContext);
