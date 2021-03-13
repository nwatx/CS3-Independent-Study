import { useGetQuestions } from "../../../hooks/useFirestore";
import { useRouter } from "next/router";
import { db } from "../../../config";
import { Skeleton } from "@chakra-ui/react";
import { useState } from "react";
import { CompeteRound } from "../../../interfaces/Game";
import RoundComponent from "../../../components/Game/Rounds/RoundComponent";
import TutorialLayout from "../../../components/TutorialLayout";
import { useUser, UseUserInterface } from "../../../context/UserProvider";
import { analyticsEvent } from "../../../util/gtag";

export const Game = () => {
	const router = useRouter();
	const id = router.query.id as string;

	console.log(`Joined game with id: ${id}`);

	const { games }: UseUserInterface = useUser();

	// console.log("games", games);

	// console.log(games, id);

	analyticsEvent({
		action: 'joined_game',
		value: id
	})

	if(games.filter(e => e.id === id).length > 0) {
		router.push(`/game/${id}/grade`)
	}

	// const roundsRef = db.games.doc(`${id}/rounds/`);
	const roundsRef = db.root.collection(`/games/${id}/rounds/`);
	const { rounds, error } = useGetQuestions(roundsRef);

	const [playableRounds, setPlayableRounds] = useState<CompeteRound[]>([]);

	if (rounds) {
		rounds.filter((value) => {
			// console.log(value);
			return (
				value.start_time.seconds < new Date().getTime() / 1000 &&
				value.end_time.seconds > new Date().getTime() / 1000
			);
		});

		rounds.sort((a, b) => a.start_time.nanoseconds - b.start_time.nanoseconds);
		if (rounds !== playableRounds) setPlayableRounds(rounds);
	}

	return (
		<TutorialLayout>
			<div className="flex w-full justify-center">
				<Skeleton isLoaded={Boolean(rounds)}>
					{error || rounds.length === 0 ? (
						<div>Error could not find game with id: {id} </div>
					) : (
						<>
							{playableRounds.map((round, index) => {
								// console.log(round, index);
								return (
									<RoundComponent
										roundId={round.id}
										gameId={id}
										key={index}
										id={index}
										round={round}
									/>
								);
							})}
						</>
					)}
				</Skeleton>
			</div>
		</TutorialLayout>
	);
};

export default Game;