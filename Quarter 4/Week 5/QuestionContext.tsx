import { createContext, useContext, useEffect, useState } from "react";
import useWs from "../hooks/makeWs";
import { GoNextDataAction } from "../types/GameActions";

const choices = ["benq", "tourist", "dkasabov", "nwatx"];

type QuestionContextType = {
	questionIdx: number;
	answerChoices: string[];
	[key: string]: any;
};

const QuestionContext = createContext<QuestionContextType>({
	questionIdx: 0,
	answerChoices: [],
});

export const QuestionProvider = ({ children }) => {
	const [questionIdx, setQuestionIdx] = useState(0);
	const [questionText, setQuestionText] = useState("");
	const [answerChoices, setAnswerChoices] = useState<string[]>(choices);

	const submitQuestion = (answer: string | number) => {
		console.log("submitted");
	};

	const incrementQuestion = () => {
		setQuestionIdx(questionIdx + 1);
	};

	useEffect(() => {
		console.log(questionIdx);
	}, [questionIdx])

	const updateQuestion = (questionData: GoNextDataAction) => {
		incrementQuestion();
		setQuestionText(questionData.data.question);
		setAnswerChoices(questionData.data?.choices);
		console.log(questionData);
	};

	return (
		<QuestionContext.Provider
			value={{
				questionIdx,
				questionText,
				answerChoices,
				submitQuestion,
				updateQuestion,
			}}
		>
			{children}
		</QuestionContext.Provider>
	);
};

export const useQuestion = () => useContext(QuestionContext);
